PORTNAME=	cyrus2dovecot
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.cyrus2dovecot.sw.fu-berlin.de/download/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Cyrus folders to Dovecot
WWW=		http://www.cyrus2dovecot.sw.fu-berlin.de/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

USES=		perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	pod2man --section=1 --release=${PORTVERSION} \
		--name=${PORTNAME} --center=${PORTNAME}" user guide" \
		${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
