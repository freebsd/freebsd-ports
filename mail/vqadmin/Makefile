# New ports collection makefile for: vqadmin
# Date created:		29 Mar 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	vqadmin
PORTVERSION=	2.3.5
CATEGORIES=	mail
MASTER_SITES= 	http://www.inter7.com/devel/ \
		http://www.inter7.com/vqadmin/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A cgi-based Virtual Qmail Domains Administrator

LIB_DEPENDS=	getline.1:${PORTSDIR}/devel/libgetline
BUILD_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

GNU_CONFIGURE=	YES
USE_REINPLACE=	YES

CGIBINDIR?=	${PREFIX}/www/cgi-bin.default
WEBDATADIR?=	${PREFIX}/www/data.default

CONFIGURE_ARGS=	--enable-cgibindir=${CGIBINDIR} \
		--enable-htmldir=${WEBDATADIR}

.include <bsd.port.pre.mk>

PLIST_SUB+=	CGIBINDIR=${CGIBINDIR} WEBDATADIR=${WEBDATADIR}

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

