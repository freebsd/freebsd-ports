% This macro demonstrates the use of the post_filter_hook
% In your .slrnrc, add the line `interpret "/usr/local/share/examples/spellutils/aspell.sl"'

%static
define aspell_file (file)
{
   variable cmd = "/usr/local/bin/newsbody -qs -k Subject -n '%s' -p /usr/local/bin/aspell -- -c -x %%f";
   () = system (sprintf (cmd, file));
}


define post_filter_hook (file)
{
   variable rsp;
   variable cmd;
   
   forever 
     {
	rsp = get_response ("NnAa",
			    "Select Filter? \001None, \001Aspell");
	
	switch (rsp)
	  {
	   case 'a' or case 'A':
	     aspell_file (file);
	  }
	  {
	   case 'n' or case 'N':
	     return;
	  }
     }
}
