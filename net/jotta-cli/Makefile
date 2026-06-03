PORTNAME=	jotta-cli
DISTVERSION=	0.17.159692
CATEGORIES=	net
_SITESPREFIX=	https://repo.jotta.us/archives/freebsd/
_DISTPREFIX=	${PORTNAME}-${DISTVERSION}_freebsd_
.ifmake makesum || makeplist || distclean
MASTER_SITES=	${ONLY_FOR_ARCHS:S|i386|386|:C|(.*)|${_SITESPREFIX}\1/|}
DISTFILES=	${ONLY_FOR_ARCHS:S|i386|386|:C|(.*)|${_DISTPREFIX}\1${EXTRACT_SUFX}|}
.else
MASTER_SITES=	${_SITESPREFIX}${ARCH:S|i386|386|}/
DISTNAME=	${_DISTPREFIX}${ARCH:S|i386|386|}
.endif

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Jotta Cloud Daemon and Command-Line Interface
WWW=		https://www.jottacloud.com

LICENSE=	UNKNOWN
LICENSE_NAME=	"Jottacloud Terms and Service"
LICENSE_TEXT=	"JottaCloud has its own terms and conditions available at https://www.jottacloud.com/en/terms.html"
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USE_RC_SUBR=	jottad

NO_BUILD=	yes
SUB_FILES=	jottad pkg-message

USERS=		jottad
GROUPS=		jottad

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/jottad
	${INSTALL_SCRIPT} ${WRKDIR}/jottad ${STAGEDIR}${PREFIX}/etc/rc.d/jottad
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/jotta-cli ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/jottad ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKDIR}/etc/jottad/config.ini ${STAGEDIR}${PREFIX}/etc/jottad/config.ini.sample

post-install:
	${MKDIR} ${STAGEDIR}/var/lib/jottad

.include <bsd.port.mk>
