# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>

PORTNAME=	pgpdump
PORTVERSION=	0.34
CATEGORIES=	security
MASTER_SITES=	https://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PGP packet visualizer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pgpdump \
		share/man/man1/pgpdump.1.gz

CPE_VENDOR=	pgpdump_project

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pgpdump.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
