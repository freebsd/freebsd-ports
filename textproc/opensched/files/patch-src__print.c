*** src/print.c.org	Wed Jan 31 14:29:34 2001
--- src/print.c	Wed Jan 31 14:30:44 2001
***************
*** 579,612 ****
  
      SortMilestones();
  
!     fprintf(f, "\\subsection{Milestone List}\n\\label{milestones}\n\n");
! 
!     fprintf(f, "\\begin{itemize}\n");
! 
!     for ( i = 0; i < Nmilestones; ++i )
!     {
  	m = sorted_milestones[i].milestone;
! 
  	fprintf(f, "\\item ");
  	if ( milestone_ids )
! 	    fprintf(f, "%s %s\\\\",
! 		    TeXFix(buf1,m->id),
! 		    TeXFix(buf2,m->name));
  	else
! 	    fprintf(f, "%s\\\\",
! 		    TeXFix(buf2,m->name));
  	fprintf(f, " \\emph{%s}\n\n",
  		days[m->day].s);
  	if ( m->bday != INVALIDDAYNO )
  	{
! 	    fprintf(f, "Baseline\\\\\emph{%s}\n",
! 		    days[m->bday].s);
  	}
  	fprintf(f, "\n\n");
!     }
! 
!     fprintf(f, "\\end{itemize}\n\n");
  
      fprintf(f,"\\subsection{Resources And Task Assignment}\n\n");
  
      for( rl=reslist; rl!=NULL; rl=rl->next )
--- 579,614 ----
  
      SortMilestones();
  
!     if (Nmilestones > 0) {
!       fprintf(f, "\\subsection{Milestone List}\n\\label{milestones}\n\n");
!       
!       fprintf(f, "\\begin{itemize}\n");
!       
!       for ( i = 0; i < Nmilestones; ++i )
!       {
  	m = sorted_milestones[i].milestone;
!         
  	fprintf(f, "\\item ");
  	if ( milestone_ids )
!           fprintf(f, "%s %s\\\\",
!                   TeXFix(buf1,m->id),
!                   TeXFix(buf2,m->name));
  	else
!           fprintf(f, "%s\\\\",
!                   TeXFix(buf2,m->name));
  	fprintf(f, " \\emph{%s}\n\n",
  		days[m->day].s);
  	if ( m->bday != INVALIDDAYNO )
  	{
!           fprintf(f, "Baseline\\\\\emph{%s}\n",
!                   days[m->bday].s);
  	}
  	fprintf(f, "\n\n");
!       }
  
+       fprintf(f, "\\end{itemize}\n\n");
+     }
+     
      fprintf(f,"\\subsection{Resources And Task Assignment}\n\n");
  
      for( rl=reslist; rl!=NULL; rl=rl->next )
