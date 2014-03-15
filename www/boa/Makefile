# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	boa
PORTVERSION=	0.94.14.r21
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.boa.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	High performance single-tasking web server

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

INFO=		boa
MAN8=		boa.8

PORTDOCS=	boa.texi boa.html boa.txt boa_banner.png

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/examples/boa.conf ${WRKSRC}/src/defines.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/boa ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/boa_indexer ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/docs/boa.8 ${PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/boa.conf ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/cgi-test.cgi ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/nph-test.cgi ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/resolver.pl ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/docs/boa.info ${PREFIX}/info

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/boa.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/boa.sh.sample \
			startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/boa.sh.sample \
			${PREFIX}/etc/rc.d; \
	fi

.include <bsd.port.mk>
