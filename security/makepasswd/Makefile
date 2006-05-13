# New ports collection makefile for:	makepasswd
# Date created:				7 March 2003
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	makepasswd
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCHFILES=	${PORTNAME}_${PORTVERSION}-2.diff.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Random password generator

NO_BUILD=	yes
USE_PERL5_RUN=	yes

RUN_DEPENDS+=	${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		makepasswd.1
DOCS=		CHANGES README

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s/use	bytes;/#use	bytes;/" ${WRKSRC}/makepasswd
	${REINPLACE_CMD} -e "s/\/dev\/random/\/dev\/urandom/" ${WRKSRC}/makepasswd
	${REINPLACE_CMD} -e "s/\/dev\/random/\/dev\/urandom/" ${WRKSRC}/makepasswd.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepasswd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
