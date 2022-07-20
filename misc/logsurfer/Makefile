PORTNAME=	logsurfer
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.crypt.gen.nz/logsurfer/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Process logfiles and conditionally perform certain actions

LICENSE=	GPLv2 ISCL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/DISCLAIMER

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-etcdir=${ETCDIR}
USES=		desthack
USE_RC_SUBR=	logsurfer

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
