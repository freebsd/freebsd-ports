--  The FSF GNAT 4.9 Project code is hopelessly too modern for AdaBrowse to
--  hook into it.  Just build AdaBrowse without it.

pragma License (GPL);

with AD.Projects.Impl_No;
private package AD.Projects.Impl
  renames AD.Projects.Impl_No;
