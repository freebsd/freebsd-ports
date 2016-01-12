# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	boa
DISTVERSION=	0.94.14rc21
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance single-tasking web server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake makeinfo tar:bzip2
CPE_VENDOR=	${PORTVERSION:C/\.r/./}
GNU_CONFIGURE=	yes

INFO=		boa

PORTDOCS=	boa.texi boa.html boa.txt boa_banner.png
PORTEXAMPLES=	boa.conf cgi-test.cgi nph-test.cgi resolver.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

SUB_FILES=	pkg-message

PLIST_FILES=	etc/rc.d/boa.sh.sample \
		man/man8/boa.8.gz \
		sbin/boa \
		sbin/boa_indexer \

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/examples/boa.conf ${WRKSRC}/src/defines.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/boa_indexer ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/docs/boa.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_SCRIPT} ${FILESDIR}/boa.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
