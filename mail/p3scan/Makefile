# New ports collection makefile for:	p3scan
# Date created:				20 Februari 2003
# Whom:	      				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	p3scan
PORTVERSION=	2.3.2
PORTREVISION=	4
CATEGORIES=	mail net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	A transparent POP3-Proxy with virus-scanning capabilities

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

PLIST_FILES=	etc/p3scan/p3scan.conf.sample etc/p3scan/p3scan.mail.sample \
		sbin/p3scan
PLIST_DIRS=	etc/p3scan

USE_GMAKE=	yes
MAKE_ENV=	_LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" GMAKE=${GMAKE}
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX} NONEXISTENT=${NONEXISTENT} PASSWD=/etc/passwd
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	UVSCAN "Use UVSCAN" off

PORTDOCS=	AUTHORS CHANGELOG LICENSE NEWS README
MAN8=		p3scan.8 p3scan_readme.8
MANCOMPRESSED=	yes

USE_RC_SUBR=	p3scan
SUB_FILES=	p3scan pkg-message

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_UVSCAN)
RUN_DEPENDS+=	uvscan:${PORTSDIR}/security/vscan
.endif

do-install:
.if !exists(${PREFIX}/etc/p3scan)
	${MKDIR} ${PREFIX}/etc/p3scan
.endif
.if !exists(/var/spool/p3scan)
	${MKDIR} /var/spool/p3scan
.endif
	${CHOWN} mailnull:mail /var/spool/p3scan
	${INSTALL_PROGRAM} ${WRKSRC}/p3scan ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/p3scan.conf ${PREFIX}/etc/p3scan/p3scan.conf.sample
	${INSTALL_DATA} ${WRKSRC}/p3scan-en.mail ${PREFIX}/etc/p3scan/p3scan.mail.sample
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${f}.gz ${MAN8PREFIX}/man/man8/
.endfor
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
