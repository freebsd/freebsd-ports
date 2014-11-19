# Created by: Securedog <securedog@users.sourceforge.jp>
# $FreeBSD$

PORTNAME=	pkg_replace
PORTVERSION=	20141022
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://member.tokoha-u.ac.jp/~kdeguchi/download/

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Utility for upgrading installed packages

USES=		tar:xz
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/pkg_replace \
		man/man1/pkg_replace.1.gz \
		"@sample %%ETCDIR%%/pkg_replace.conf.sample"

SUB_FILES=	pkg-message

PORTDOCS=	README README.ja

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g;s|%%PKGCOMPATDIR%%|${PKGCOMPATDIR}|g' \
		${WRKSRC}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
