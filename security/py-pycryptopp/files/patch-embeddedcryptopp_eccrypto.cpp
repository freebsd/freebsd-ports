--- embeddedcryptopp/eccrypto.cpp.orig	2010-09-21 04:36:16.000000000 +0000
+++ embeddedcryptopp/eccrypto.cpp
@@ -435,7 +435,7 @@ template <class EC> void DL_GroupParamet
 	StringSource ssG(param.g, true, new HexDecoder);
 	Element G;
 	bool result = GetCurve().DecodePoint(G, ssG, (size_t)ssG.MaxRetrievable());
-	SetSubgroupGenerator(G);
+	this->SetSubgroupGenerator(G);
 	assert(result);
 
 	StringSource ssN(param.n, true, new HexDecoder);
@@ -591,7 +591,7 @@ bool DL_GroupParameters_EC<EC>::Validate
 	if (level >= 2 && pass)
 	{
 		const Integer &q = GetSubgroupOrder();
-		Element gq = gpc ? gpc->Exponentiate(this->GetGroupPrecomputation(), q) : ExponentiateElement(g, q);
+		Element gq = gpc ? gpc->Exponentiate(this->GetGroupPrecomputation(), q) : this->ExponentiateElement(g, q);
 		pass = pass && IsIdentity(gq);
 	}
 	return pass;
@@ -629,7 +629,7 @@ void DL_PublicKey_EC<EC>::BERDecodePubli
 	typename EC::Point P;
 	if (!this->GetGroupParameters().GetCurve().DecodePoint(P, bt, size))
 		BERDecodeError();
-	SetPublicElement(P);
+	this->SetPublicElement(P);
 }
 
 template <class EC>
