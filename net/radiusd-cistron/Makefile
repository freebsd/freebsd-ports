# Created by: john@nlc.net.au
# $FreeBSD$

PORTNAME=	radiusd-cistron
PORTVERSION=	1.6.8
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.radius.cistron.nl/pub/radius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RADIUS-compliant remote authentication and accounting server

CONFLICTS?=	freeradius-0.* gnu-radius-1.* openradius-0.*

USES=		shebangfix
SHEBANG_FILES=	src/checkrad.pl
MAKEFILE=	Makefile.BSD
RADIUS_DIR=	${PREFIX}/etc/raddb
MAKE_ENV+=	RADIUS_DIR="${RADIUS_DIR}" DESTROOT="${STAGEDIR}"
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	radiusd-cistron radrelay-cistron
DOCFILES=	COPYRIGHT INSTALL doc/ChangeLog doc/README doc/README.Y2K \
		doc/README.cisco doc/README.pam doc/README.proxy \
		doc/README.simul doc/README.usersfile

OPTIONS_DEFINE=	PAM DOCS
OPTIONS_DEFAULT=PAM
OPTIONS_SUB=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}/var/log/radacct

.include <bsd.port.mk>
