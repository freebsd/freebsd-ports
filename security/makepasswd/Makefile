# Created by: Toni Viemerö <toni.viemero@iki.fi>
# $FreeBSD$

PORTNAME=	makepasswd
PORTVERSION=	1.10
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Random password generator

LICENSE=	GPLv1

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

RUN_DEPENDS+=	p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Crypt-OpenSSL-Random>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-Random

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		makepasswd.1
DOCS=		CHANGES README

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s/use	bytes;/#use	bytes;/" ${WRKSRC}/makepasswd

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
