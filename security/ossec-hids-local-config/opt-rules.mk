RULES_MANAGED_CONF=	100.rules.conf
RULES_LOCAL_CONF=	500.rules.local.conf

RULES_DESC=		Alerting Rules

RULES_FILES=		config cmdout

# Default rules
RULES_DEFAULT_OPTION=	DEFAULT_R
RULES_DEFAULT_DESC=	Rules provided by OSSEC
RULES_DEFAULT_DEFINE=	server local
RULES_DEFAULT_DEFAULT=	server local
RULES_OPTIONS+=		RULES_DEFAULT

# Config rules
RULES_CONFIG_OPTION=	CONFIG_R
RULES_CONFIG_DESC=	Alert changes of the OSSEC main configuration files
RULES_CONFIG_DEFINE=	server local
RULES_CONFIG_DEFAULT=	server local
RULES_OPTIONS+=		RULES_CONFIG

# Command output rules
RULES_CMDOUT_OPTION=	CMDOUT_R
RULES_CMDOUT_DESC=	Alert changes of output of the monitored commands
RULES_CMDOUT_DEFINE=	server local
RULES_CMDOUT_DEFAULT=	server local
RULES_OPTIONS+=		RULES_CMDOUT
