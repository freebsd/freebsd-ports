# New ports collection makefile for:	boa
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	boa
PORTVERSION=	0.94.14.r17
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.boa.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	High performance single-tasking web server

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN8=		boa.8

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
	@${INSTALL_DATA} ${WRKSRC}/docs/boa.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/boa.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/boa.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/boa_banner.png ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/boa.info ${PREFIX}/info
	@install-info ${PREFIX}/info/boa.info ${PREFIX}/info/dir
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/boa.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/boa.sh.sample \
			startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/boa.sh.sample \
			${PREFIX}/etc/rc.d; \
	fi

.include <bsd.port.mk>
