# New ports collection makefile for:	p3scan
# Date created:				20 Februari 2003
# Whom:	      				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	p3scan
PORTVERSION=	2.1
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	A transparent POP3-Proxy with virus-scanning capabilities

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_GETOPT_LONG=yes
MAKE_ENV=	_LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" GMAKE=${GMAKE}
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX} NONEXISTENT=${NONEXISTENT} PASSWD=/etc/passwd

OPTIONS=	UVSCAN "Use UVSCAN" on

PORTDOCS=	AUTHORS CHANGELOG LICENSE NEWS README

MAN8=		p3scan.8 p3scan_readme.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_UVSCAN)
RUN_DEPENDS+=	uvscan:${PORTSDIR}/security/vscan
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p3scan ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/p3scan.conf ${PREFIX}/etc/p3scan.conf.sample
	${INSTALL_DATA} ${WRKSRC}/p3scan-en.mail ${PREFIX}/etc/p3scan.mail.sample
	${INSTALL_SCRIPT} ${FILESDIR}/p3scan.sh ${PREFIX}/etc/rc.d/
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
	@${SED} -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
