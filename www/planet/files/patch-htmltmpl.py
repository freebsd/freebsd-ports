*** htmltmpl.py Mon Sep 26 19:14:38 2005
--- htmltmpl.py Mon Sep 26 19:00:07 2005
***************
*** 267,277 ****
          fd = file.fileno()
          if LOCKTYPE == LOCKTYPE_FCNTL:
              if lock == LOCK_SH:
!                 fcntl.fcntl(fd, fcntl.LOCK_SH)
              elif lock == LOCK_EX:
!                 fcntl.fcntl(fd, fcntl.LOCK_EX)
              elif lock == LOCK_UN:
!                 fcntl.fcntl(fd, fcntl.LOCK_UN)
              else:
                  raise TemplateError, "BUG: bad lock in lock_file"
          elif LOCKTYPE == LOCKTYPE_MSVCRT:
--- 267,277 ----
          fd = file.fileno()
          if LOCKTYPE == LOCKTYPE_FCNTL:
              if lock == LOCK_SH:
!                 fcntl.flock(fd, fcntl.LOCK_SH)
              elif lock == LOCK_EX:
!                 fcntl.flock(fd, fcntl.LOCK_EX)
              elif lock == LOCK_UN:
!                 fcntl.flock(fd, fcntl.LOCK_UN)
              else:
                  raise TemplateError, "BUG: bad lock in lock_file"
          elif LOCKTYPE == LOCKTYPE_MSVCRT:
