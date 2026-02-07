PORTNAME=	pam-modules
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/pam-modules/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Collection of modules for PAM
WWW=		https://puszcza.gnu.org.ua/software/pam-modules/pam-modules.html

LICENSE=	GPLv3

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fshadow
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		pam-modules

OPTIONS_DEFINE=		GROUPMEMBER MYSQL NIS PGSQL REGEX SYSLOG
OPTIONS_DEFAULT=	GROUPMEMBER REGEX SYSLOG
OPTIONS_SUB=		yes

GROUPMEMBER_DESC=	Build pam_groupmember
MYSQL_DESC=		Build pam_mysql
NIS_DESC=		Build pam_innetgr
PGSQL_DESC=		Build pam_pgsql
REGEX_DESC=		Build pam_regex
SYSLOG_DESC=		Build pam_log

GROUPMEMBER_CONFIGURE_ENABLE=	groupmember
MYSQL_USES=			mysql
MYSQL_CONFIGURE_ENABLE=		mysql
MYSQL_CFLAGS+=			-I${LOCALBASE}/include
NIS_CONFIGURE_ENABLE=		NIS
PGSQL_USES=			pgsql
PGSQL_CONFIGURE_ENABLE=		pgsql
PGSQL_VARS=			WANT_PGSQL=client
REGEX_CONFIGURE_ENABLE=		regex
SYSLOG_CONFIGURE_ENABLE=	log

.include <bsd.port.mk>
