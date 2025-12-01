PORTNAME=	tmux
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tmux/tmux/releases/download/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Terminal Multiplexer
WWW=		https://tmux.github.io/

LICENSE=	GPLv2 ISCL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC_bash}/COPYING
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING
LICENSE_DISTFILES_GPLv2=	${DISTFILE_bash}
LICENSE_DISTFILES_ISCL=		${DISTNAME}${EXTRACT_SUFX}

USES=		cpe pkgconfig

CPE_VENDOR=	tmux_project

USE_GITHUB=	nodefault
GH_TUPLE=	imomaliev:tmux-bash-completion:8da7f79:bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-utempter \
		--sysconfdir=${PREFIX}/etc

CONFLICTS_INSTALL=	tmux23

PLIST_FILES=	bin/tmux \
		etc/bash_completion.d/tmux \
		share/man/man1/tmux.1.gz

PORTDOCS=	CHANGES README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES LIBEVENT_STATIC UTF8PROC

LIBEVENT_STATIC_DESC=	Build with static libevent
UTF8PROC_DESC=		Build with utf8proc support

LIBEVENT_STATIC_BUILD_DEPENDS=		${LOCALBASE}/lib/libevent.a:devel/libevent
LIBEVENT_STATIC_LIB_DEPENDS_OFF=	libevent.so:devel/libevent
LIBEVENT_STATIC_VARS=			LESTATIC=${LOCALBASE}/lib/libevent.a

UTF8PROC_LIB_DEPENDS=		libutf8proc.so:textproc/utf8proc
UTF8PROC_USES=			localbase
UTF8PROC_CONFIGURE_ENABLE=	utf8proc

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1401502 || ${OSVERSION} >= 1500000 && \
	${OSVERSION} < 1500020)
USES+=		ncurses:port
.else
USES+=		ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' ${WRKSRC}/CHANGES \
		${WRKSRC}/tmux.h

post-configure-LIBEVENT_STATIC-on:
	${REINPLACE_CMD} -e '/LIBS/s|-levent[^[:blank:]]*|${LESTATIC}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC_bash}/completions/tmux ${STAGEDIR}${PREFIX}/etc/bash_completion.d/tmux

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
