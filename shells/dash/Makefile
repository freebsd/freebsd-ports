PORTNAME=	dash
PORTVERSION=	0.5.12
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	POSIX-compliant implementation of /bin/sh
WWW=		http://gondor.apana.org.au/~herbert/dash/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
# SIGRTMAX is larger than NSIG*2 which mksignames.c does not support.  Just
# disable RT signal handling.
CFLAGS+=	-DUNUSABLE_RT_SIGNALS

USES=		cpe gmake

PLIST_FILES=	bin/dash \
		share/man/man1/dash.1.gz
PORTDOCS=	ChangeLog

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/COMMON_CFLAGS =/ s|$$| ${CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
