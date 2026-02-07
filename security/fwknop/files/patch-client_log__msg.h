*** client/log_msg.h.orig	Sat Apr  3 21:59:58 2021
--- client/log_msg.h	Sat Apr  3 22:00:14 2021
***************
*** 38,44 ****
      LOG_VERBOSITY_INFO,         /*!< Constant to define a INFO message */
      LOG_VERBOSITY_DEBUG,        /*!< Constant to define a DEBUG message */
      LOG_LAST_VERBOSITY
! } log_level_t;

  #define LOG_DEFAULT_VERBOSITY   LOG_VERBOSITY_NORMAL    /*!< Default verbosity to use */

--- 38,44 ----
      LOG_VERBOSITY_INFO,         /*!< Constant to define a INFO message */
      LOG_VERBOSITY_DEBUG,        /*!< Constant to define a DEBUG message */
      LOG_LAST_VERBOSITY
! };

  #define LOG_DEFAULT_VERBOSITY   LOG_VERBOSITY_NORMAL    /*!< Default verbosity to use */

