# New ports collection makefile for:	boa
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	boa
PORTVERSION=	0.94.12.r2
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	sysadmin@alexdupre.com

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN8=		boa.8

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/defines.h \
		${WRKSRC}/../boa.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/boa ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/boa_indexer ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/../docs/boa.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/../boa.conf ${PREFIX}/etc/boa.conf.sample
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/../examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../docs/boa.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../docs/boa_banner.png ${DOCSDIR}
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/boa.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/boa.sh.sample \
			startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/boa.sh.sample \
			${PREFIX}/etc/rc.d; \
	fi

.include <bsd.port.mk>
