--- libclamav/disasm.c
+++ libclamav/disasm.c
@@ -1545,8 +1545,12 @@ static uint8_t *disasm_x86(uint8_t *command, unsigned int len, struct DISASMED *
 	    GETBYTE(b);
 	    shiftme+=b<<(i*8);
 	  }
-	  shiftme<<=((8-mod)*8);
-	  s->args[reversed].arg.marg.disp=shiftme>>((8-mod)*8);
+	  if (mod) {
+	      shiftme<<=((8-mod)*8);
+	      s->args[reversed].arg.marg.disp=shiftme>>((8-mod)*8);
+	  } else {
+	      s->args[reversed].arg.marg.disp=0;
+	  }
 	} else {
 	  if (mod==0 && rm==6) {
 	    s->args[reversed].arg.marg.r1=REG_INVALID;
