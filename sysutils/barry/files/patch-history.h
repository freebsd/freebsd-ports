--- src/history.h.bak	Sun Jun  8 22:09:10 2003
+++ src/history.h	Sun Apr 24 02:18:42 2005
@@ -22,44 +22,7 @@
 
 namespace Barry
 {
-	class History;
-
-	class Command
-	{
-		public:
-			enum CreationFlags {
-				None = 0x0, Run = 0x1, Register = 0x2
-			};
-			virtual ~Command();
-
-			template <class T>
-			static T *create( CreationFlags flags = None )
-			{
-				T *cmd = new T;
-				if ( flags & Register )
-					History::self().registerCommand( cmd );
-				if ( flags & Run )
-					cmd->exec();
-				return cmd;
-			}
-
-			void unexec();
-			void exec();
-			virtual QString text() const = 0;
-
-		protected:
-			Command();
-			bool executed() const { return m_executed; }
-
-		private:
-			Command( const Command &rhs );
-			Command &operator=( const Command &rhs );
-
-			virtual void doExec() = 0;
-			virtual void doUnexec() = 0;
-
-			bool m_executed;
-	};
+	class Command;
 
 	class History : public QObject
 	{
@@ -100,6 +63,43 @@
 			unsigned int m_maxEntries;
 			KToolBarPopupAction *m_backAction;
 			KToolBarPopupAction *m_forwardAction;
+	};
+
+	class Command
+	{
+		public:
+			enum CreationFlags {
+				None = 0x0, Run = 0x1, Register = 0x2
+			};
+			virtual ~Command();
+
+			template <class T>
+			static T *create( CreationFlags flags = None )
+			{
+				T *cmd = new T;
+				if ( flags & Register )
+					History::self().registerCommand( cmd );
+				if ( flags & Run )
+					cmd->exec();
+				return cmd;
+			}
+
+			void unexec();
+			void exec();
+			virtual QString text() const = 0;
+
+		protected:
+			Command();
+			bool executed() const { return m_executed; }
+
+		private:
+			Command( const Command &rhs );
+			Command &operator=( const Command &rhs );
+
+			virtual void doExec() = 0;
+			virtual void doUnexec() = 0;
+
+			bool m_executed;
 	};
 };
 
