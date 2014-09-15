# Created by: Hammurabi Mendes <hmendes@brturbo.com>
# $FreeBSD$

PORTNAME=	ssh-gui
PORTVERSION=	0.7.1
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end for ssh which can open multiple xterms

USE_GNOME=	gtk12

ALL_TARGET=	ssh-gui

PLIST_FILES=	bin/ssh-gui
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if !exists(/usr/bin/ssh) && !exists(${LOCALBASE}/bin/ssh)
RUN_DEPENDS+=	ssh:${PORTSDIR}/security/openssh-portable
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s|(CC)=.*|\1=${CC}|" -e "s|(CFLAGS)=-Wall|\1\+=|" \
		-e "s|glib-config|${GLIB_CONFIG}|" -e "s|gtk-config|${GTK_CONFIG}|" \
		${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
