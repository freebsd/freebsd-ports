# New ports collection makefile for:	ssh-gui
# Date created:	Fri Nov 30 22:14:14 BRST 2001
# Whom:         Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	ssh-gui
PORTVERSION=	0.7.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hmendes@brturbo.com

RUN_DEPENDS=	ssh:${PORTSDIR}/security/openssh

USE_GNOMENG=	yes
USE_GNOME=	gtk12
ALL_TARGET=	ssh-gui

DOC_FILES=	README

post-patch:
	@${PERL} -pi.orig -e "s|^CC=.+$$||;s|(CFLAGS)=-Wall|\1\+=|; \
		s|glib-config|${GLIB_CONFIG}|;s|gtk-config|${GTK_CONFIG}|" \
		${BUILD_WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
