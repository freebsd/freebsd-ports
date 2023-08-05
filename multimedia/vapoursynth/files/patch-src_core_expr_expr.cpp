--- src/core/expr/expr.cpp.orig	2023-06-06 12:15:18 UTC
+++ src/core/expr/expr.cpp
@@ -20,15 +20,15 @@
 
 #include <algorithm>
 #include <cassert>
-#include <charconv>
 #include <cmath>
+#include <iostream>
+#include <locale>
 #include <map>
 #include <memory>
 #include <set>
 #include <sstream>
 #include <stdexcept>
 #include <string>
-#include <string_view>
 #include <unordered_map>
 #include <unordered_set>
 #include <vector>
@@ -136,9 +136,9 @@ bool equalSubTree(const ExpressionTreeNode *lhs, const
     return true;
 }
 
-std::vector<std::string_view> tokenize(const std::string &expr)
+std::vector<std::string> tokenize(const std::string &expr)
 {
-    std::vector<std::string_view> tokens;
+    std::vector<std::string> tokens;
     auto it = expr.begin();
     auto prev = expr.begin();
 
@@ -147,20 +147,20 @@ std::vector<std::string_view> tokenize(const std::stri
 
         if (std::isspace(c)) {
             if (it != prev)
-                tokens.push_back({ expr.c_str() + (prev - expr.begin()), static_cast<size_t>(it - prev) });
+                tokens.push_back(expr.substr(prev - expr.begin(), it - prev));
             prev = it + 1;
         }
         ++it;
     }
     if (prev != expr.end())
-        tokens.push_back({ expr.c_str() + (prev - expr.begin()), static_cast<size_t>(expr.end() - prev) });
+        tokens.push_back(expr.substr(prev - expr.begin(), expr.end() - prev));
 
     return tokens;
 }
 
-ExprOp decodeToken(std::string_view token)
+ExprOp decodeToken(const std::string &token)
 {
-    static const std::unordered_map<std::string_view, ExprOp> simple{
+    static const std::unordered_map<std::string, ExprOp> simple{
         { "+",    { ExprOpType::ADD } },
         { "-",    { ExprOpType::SUB } },
         { "*",    { ExprOpType::MUL } },
@@ -195,26 +195,34 @@ ExprOp decodeToken(std::string_view token)
         return{ ExprOpType::MEM_LOAD_U8, token[0] >= 'x' ? token[0] - 'x' : token[0] - 'a' + 3 };
     } else if (token.substr(0, 3) == "dup" || token.substr(0, 4) == "swap") {
         size_t prefix = token[0] == 'd' ? 3 : 4;
+        size_t count = 0;
         int idx = -1;
 
-        auto result = std::from_chars(token.data() + prefix, token.data() + token.size(), idx);
-        if (idx < 0 || result.ptr != token.data() + token.size())
-            throw std::runtime_error("illegal token: " + std::string{ token });
+        try {
+            idx = std::stoi(token.substr(prefix), &count);
+        } catch (...) {
+            // ...
+        }
+
+        if (idx < 0 || prefix + count != token.size())
+            throw std::runtime_error("illegal token: " + token);
         return{ token[0] == 'd' ? ExprOpType::DUP : ExprOpType::SWAP, idx };
     } else {
         float f;
-        auto result = std::from_chars(token.data(), token.data() + token.size(), f);
-        if (result.ec == std::errc::invalid_argument)
-            throw std::runtime_error("failed to convert '" + std::string{ token } + "' to float");
-        if (result.ptr != token.data() + token.size())
-            throw std::runtime_error("failed to convert '" + std::string{ token } + "' to float, not the whole token could be converted");
+        std::string s;
+        std::istringstream numStream(token);
+        numStream.imbue(std::locale::classic());
+        if (!(numStream >> f))
+            throw std::runtime_error("failed to convert '" + token + "' to float");
+        if (numStream >> s)
+            throw std::runtime_error("failed to convert '" + token + "' to float, not the whole token could be converted");
         return{ ExprOpType::CONSTANT, f };
     }
 }
 
 ExpressionTree parseExpr(const std::string &expr, const VSVideoInfo * const srcFormats[], int numInputs)
 {
-    static constexpr unsigned char numOperands[] = {
+    constexpr unsigned char numOperands[] = {
         0, // MEM_LOAD_U8
         0, // MEM_LOAD_U16
         0, // MEM_LOAD_F16
@@ -256,16 +264,16 @@ ExpressionTree parseExpr(const std::string &expr, cons
     ExpressionTree tree;
     std::vector<ExpressionTreeNode *> stack;
 
-    for (std::string_view tok : tokens) {
+    for (const std::string &tok : tokens) {
         ExprOp op = decodeToken(tok);
 
         // Check validity.
         if (op.type == ExprOpType::MEM_LOAD_U8 && op.imm.i >= numInputs)
-            throw std::runtime_error("reference to undefined clip: " + std::string{ tok });
+            throw std::runtime_error("reference to undefined clip: " + tok);
         if ((op.type == ExprOpType::DUP || op.type == ExprOpType::SWAP) && op.imm.u >= stack.size())
-            throw std::runtime_error("insufficient values on stack: " + std::string{ tok });
+            throw std::runtime_error("insufficient values on stack: " + tok);
         if (stack.size() < numOperands[static_cast<size_t>(op.type)])
-            throw std::runtime_error("insufficient values on stack: " + std::string{ tok });
+            throw std::runtime_error("insufficient values on stack: " + tok);
 
         // Rename load operations with the correct data type.
         if (op.type == ExprOpType::MEM_LOAD_U8) {
