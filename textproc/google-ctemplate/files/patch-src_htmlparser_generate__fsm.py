--- src/htmlparser/generate_fsm.py.orig	2020-09-26 14:51:40 UTC
+++ src/htmlparser/generate_fsm.py
@@ -264,7 +264,7 @@ class FSMGenerateC(FSMGenerateAbstract):
     state_table = {}
 
     for state in self._config.states:
-      state_table[state] = [default_state for col in xrange(255)]
+      state_table[state] = [default_state for col in range(255)]
 
     # We process the transition in reverse order while updating the table.
     for i_transition in range(len(self._config.transitions) - 1, -1, -1):
@@ -281,7 +281,7 @@ class FSMGenerateC(FSMGenerateAbstract):
     # Create the inner lists which map input characters to destination states.
     for state in self._config.states:
       transition_row = []
-      for c in xrange(0, 255):
+      for c in range(0, 255):
         transition_row.append('    /* %06s */ %s' % (repr(chr(c)),
                                                      state_table[state][c]))
 
@@ -306,17 +306,17 @@ class FSMGenerateC(FSMGenerateAbstract):
   def Generate(self):
     """Returns the generated the C include statements for the statemachine."""
 
-    print '\n'.join((self._CreateHeader(),
+    print('\n'.join((self._CreateHeader(),
                      self._CreateNumStates(),
                      self._CreateStatesEnum(),
                      self._CreateStatesExternal(),
                      self._CreateStatesInternalNames(),
-                     self._CreateTransitionTable()))
+                     self._CreateTransitionTable())))
 
 
 def main():
   if len(sys.argv) != 2:
-    print "usage: generate_fsm.py config_file"
+    print("usage: generate_fsm.py config_file")
     sys.exit(1)
 
   config = FSMConfig()
