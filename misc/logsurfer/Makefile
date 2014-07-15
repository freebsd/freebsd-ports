# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	logsurfer
PORTVERSION=	1.8
CATEGORIES=	misc
MASTER_SITES=	http://www.crypt.gen.nz/logsurfer/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Process logfiles and conditionally perform certain actions

LICENSE=	BSD

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-etcdir=${ETCDIR}
USES=		desthack
USE_RC_SUBR=	logsurfer

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
