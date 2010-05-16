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

USE_OPENSSL=	yes
OPENSSL_LDFLAGS+=-lssl
USE_PYTHON=	2.0-2.5
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

MAN1=	mixminion.1
MAN5=	mixminiond.conf.5 mixminionrc.5
MAN8=	mixminiond.8

PORTDOCS=	statusfd.txt tutorial.txt

OPTIONS=	SERVER "Also install the server" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SERVER)
USE_RC_SUBR+=	mixminiond
SUB_FILES+=	pkg-message
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|share/man|man|g" ${WRKSRC}/setup.py

post-install:
.if !defined(WITHOUT_SERVER)
	@${INSTALL_DATA} ${WRKSRC}/etc/mixminiond.conf \
		${PREFIX}/etc/mixminiond.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/blacklist.conf \
		${PREFIX}/etc/blacklist.conf.sample
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
