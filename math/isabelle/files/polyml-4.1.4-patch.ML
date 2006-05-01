(*  Title:      Pure/ML-Systems/polyml-4.1.4-patch.ML
    ID:         $Id$
    Author:     Makarius

Patch for PolyML 4.1.4 to make it work with Isabelle2005.  We commit
this into ML_dbase!
*)

structure Posix =
struct
  open Posix;
  structure IO =
  struct
    open IO;
    val mkReader = mkTextReader;
    val mkWriter = mkTextWriter;
  end;
end;

structure TextIO =
struct
  open TextIO;
  fun inputLine is = Option.getOpt (TextIO.inputLine is, "");
end;

structure Substring =
struct
  open Substring;
  val all = full;
end;

