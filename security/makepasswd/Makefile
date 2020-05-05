# Created by: Toni Viemerö <toni.viemero@iki.fi>
# $FreeBSD$

PORTNAME=	makepasswd
PORTVERSION=	1.10
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCHFILES=	${PORTNAME}_${PORTVERSION}-12.diff.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Random password generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING-2.0

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	makepasswd
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS+=	p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Bytes-Random-Secure>=0:security/p5-Bytes-Random-Secure

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGES README

post-patch:
	${REINPLACE_CMD} -e "s/use	bytes;/#use	bytes;/" ${WRKSRC}/makepasswd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepasswd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
