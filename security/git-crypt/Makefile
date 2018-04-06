# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	git-crypt
PORTVERSION=	0.6.0
CATEGORIES=	security
MASTER_SITES=	https://www.agwa.name/projects/git-crypt/downloads/ \
		LOCAL/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Transparent file encryption in git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	git:devel/git \
		gpg:security/gnupg

OPTIONS_DEFINE=	MANPAGES

LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	PREFIX=${PREFIX} "CXXFLAGS=${CXXFLAGS}" \
		"LDFLAGS=${LDFLAGS}"

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_MAKE_ARGS=		ENABLE_MAN=yes \
			MANDIR=${MANPREFIX}/man \
			DOCBOOK_XSL=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

USES=		gmake ssl

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${GREP} -Rl '"gpg"' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e 's,"gpg","${LOCALBASE}/bin/gpg",'
	@${GREP} -Rl '"git"' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e 's,"git","${LOCALBASE}/bin/git",'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/git-crypt

.include <bsd.port.mk>
