LOGS_MANAGED_CONF=	150.logs.conf
LOGS_LOCAL_CONF=	550.logs.local.conf

LOGS_DESC=		Log Monitoring

# Default logs support
LOGS_BASIC_OPTION=	BASIC
LOGS_BASIC_PROFILE=	basic
LOGS_BASIC_DESC=	Basic system logs
LOGS_BASIC_DEFINE=	server local agent pushed
LOGS_BASIC_DEFAULT=	server local pushed
LOGS_OPTIONS+=		LOGS_BASIC

# Active response log support
LOGS_OSSEC_OPTION=	OSSEC
LOGS_OSSEC_PROFILE=	ossec
LOGS_OSSEC_DESC=	OSSEC active response logs
LOGS_OSSEC_DEFINE=	server local agent pushed
LOGS_OSSEC_DEFAULT=	server local pushed
LOGS_OPTIONS+=		LOGS_OSSEC

# Apache logs support
LOGS_APACHE_OPTION=	APACHE
LOGS_APACHE_PROFILE=	apache
LOGS_APACHE_DESC=	Apache logs
LOGS_APACHE_DEFINE=	server local agent pushed
LOGS_APACHE_DEFAULT=	pushed
LOGS_OPTIONS+=		LOGS_APACHE

# Nginx logs support
LOGS_NGINX_OPTION=	NGINX
LOGS_NGINX_PROFILE=	nginx
LOGS_NGINX_DESC=	Nginx logs
LOGS_NGINX_DEFINE=	server local agent pushed
LOGS_NGINX_DEFAULT=	pushed
LOGS_OPTIONS+=		LOGS_NGINX

# Radius logs support
LOGS_RADIUS_OPTION=	RADIUS
LOGS_RADIUS_PROFILE=	radius
LOGS_RADIUS_DESC=	FreeRADIUS logs
LOGS_RADIUS_DEFINE=	server local agent pushed
LOGS_RADIUS_DEFAULT=	pushed
LOGS_OPTIONS+=		LOGS_RADIUS

# Vsftpd logs support
LOGS_VSFTPD_OPTION=	VSFTPD
LOGS_VSFTPD_PROFILE=	vsftpd
LOGS_VSFTPD_DESC=	Vsftpd logs
LOGS_VSFTPD_DEFINE=	server local agent pushed
LOGS_VSFTPD_DEFAULT=	pushed
LOGS_OPTIONS+=		LOGS_VSFTPD
