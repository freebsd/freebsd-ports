# Created by: Ricky E. <codeblock@eighthbit.net>
# $FreeBSD$

PORTNAME=	gist
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	www net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Gist pastebin posting command

OPTIONS_DEFINE=	NSSCA
NSSCA_DESC=	Use certificates provided in security/ca_root_nss
.include <bsd.port.options.mk>

CONFLICTS=	p5-App-gist-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	defunkt
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	82ffb80

USE_RUBY=	YES
RUBY_NO_BUILD_DEPENDS=	YES
NO_BUILD=	YES

PLIST_FILES=	bin/gist \
		man/man1/gist.1.gz

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNSSCA}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-nssca-gist
.else
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-cert-gist
.endif

.if ${PORT_OPTIONS:MNSSCA}
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gist
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gist ${STAGEDIR}${PREFIX}/bin/gist
	${INSTALL_MAN} ${WRKSRC}/man/gist.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
