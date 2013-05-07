# ports collection makefile for: 		mixminion
# Date created: 				2004.06.11
# Whom:						freebsd-ports@rikrose.net
#
# $FreeBSD$
#

PORTNAME=	Mixminion
DISTVERSION=	0.0.8alpha3
CATEGORIES=	mail security
MASTER_SITES=	http://www.mixminion.net/dist/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Type III Anonymous Remailer

BROKEN=		Build is broken with supported python versions
DEPRECATED=	This port requires python version, we haven't in the ports tree already
EXPIRATION_DATE=2013-06-07

USE_OPENSSL=	yes
OPENSSL_LDFLAGS+=-lssl
USE_PYTHON=	2.0-2.5
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

MAN1=	mixminion.1
MAN5=	mixminiond.conf.5 mixminionrc.5
MAN8=	mixminiond.8

PORTDOCS=	statusfd.txt tutorial.txt

OPTIONS_DEFINE=	SERVER DOCS
OPTIONS_DEFAULT=	SERVER
SERVER_DESC=	Also install the server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR+=	mixminiond
SUB_FILES+=	pkg-message
PLIST_SUB+=	SERVER=""
USERS=	_${PORTNAME:L}
GROUPS=	${USERS}
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|share/man|man|g" ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MSERVER}
	@${INSTALL_DATA} ${WRKSRC}/etc/mixminiond.conf \
		${PREFIX}/etc/mixminiond.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/blacklist.conf \
		${PREFIX}/etc/blacklist.conf.sample
	@-${MKDIR} /var/spool/mixminion
	@${CHOWN} _mixminion:_mixminion /var/spool/mixminion
	@${CHMOD} 0700 /var/spool/mixminion
	@-${MKDIR} /var/run/mixminion
	@${CHOWN} _mixminion:_mixminion /var/run/mixminion
	@${CHMOD} 0700 /var/run/mixminion
	@-${TOUCH} /var/log/mixminion
	@${CHOWN} _mixminion:_mixminion /var/log/mixminion
	@${CHMOD} 0700 /var/log/mixminion
	@${CAT} ${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
