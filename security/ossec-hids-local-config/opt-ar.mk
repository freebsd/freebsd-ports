AR_MANAGED_CONF=	110.active-response.conf
AR_LOCAL_CONF=		510.active-response.local.conf

AR_DESC=		Active Response

# Default commands
AR_CMDS_DEFAULT_OPTION=	DEFAULT_C
AR_CMDS_DEFAULT_DESC=	Commands provided by OSSEC
AR_CMDS_DEFAULT_DEFINE=	server local
AR_CMDS_DEFAULT_DEFAULT=server local
AR_OPTIONS+=		AR_CMDS_DEFAULT

# Config merge commands
AR_CMDS_MERGE_OPTION=	MERGE_C
AR_CMDS_MERGE_DESC=	Commands to merge configuration files
AR_CMDS_MERGE_DEFINE=	server local
AR_CMDS_MERGE_DEFAULT=	server local
AR_OPTIONS+=		AR_CMDS_MERGE

# Config merge active response
AR_MERGE_OPTION=	MERGE_AR
AR_MERGE_DESC=		Merge configuration files when they change
AR_MERGE_DEFINE=	server local
AR_MERGE_DEFAULT=	server local
AR_OPTIONS+=		AR_MERGE

# OSSEC restart active response
AR_RESTART_OPTION=	RESTART_AR
AR_RESTART_DESC=	Restart OSSEC when main configuration files change
AR_RESTART_DEFINE=	server local
AR_RESTART_DEFAULT=	server local
AR_OPTIONS+=		AR_RESTART

# Host deny active response
AR_HOSTDENY_OPTION=	HOSTDENY_AR
AR_HOSTDENY_DESC=	Block the attacker's IP using access control files
AR_HOSTDENY_DEFINE=	server local
AR_HOSTDENY_DEFAULT=
AR_OPTIONS+=		AR_HOSTDENY

# Firewall drop active response
AR_FWDROP_OPTION=	FWDROP_AR
AR_FWDROP_DESC=		Block the attacker's IP on the firewall
AR_FWDROP_DEFINE=	server local
AR_FWDROP_DEFAULT=
AR_OPTIONS+=		AR_FWDROP
