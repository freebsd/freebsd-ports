PORTNAME=	empty
PORTVERSION=	0.6.23d
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zmey20000@yahoo.com
COMMENT=	Expect-like tool for pure shell
WWW=		https://empty.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		tar:tgz

DOCS=		CHANGELOG COPYRIGHT README.txt README_CYGWIN
EXAMPLES=	README.txt em_ssh.sh em_ssh_2.sh em_sh.sh \
		em_telnet.sh em_telnet_2.sh emsu.sh
MAKE_ARGS+=	CC="${CC}"

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/empty ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/empty.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR} \
		  ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
