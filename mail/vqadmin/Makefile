# Created by: nbm
# $FreeBSD$

PORTNAME=	vqadmin
PORTVERSION=	2.3.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CGI-based Virtual Qmail Domains Administrator

BUILD_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:mail/vpopmail
RUN_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:mail/vpopmail

GNU_CONFIGURE=	YES

USES=		qmail:vars

CGIBINDIR?=	www/cgi-bin-dist
WEBDATADIR?=	www/data-dist

CONFIGURE_ARGS=	--enable-cgibindir=${STAGEDIR}${PREFIX}/${CGIBINDIR} \
		--enable-htmldir=${STAGEDIR}${PREFIX}/${WEBDATADIR} \
		--enable-qmaildir=${QMAIL_PREFIX}

PLIST_SUB+=	CGIBINDIR=${CGIBINDIR} WEBDATADIR=${WEBDATADIR}

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
