# New ports collection makefile for:	elmo
# Date created:				2003-09-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	elmo
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20devel/${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Receive, filter, read, compose and send mail at the text console

CONFLICTS=	elmo-[0-9]*

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_PERL5_RUN=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		elmo.1 elmoconf.pl.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgpgme03.so) || defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme03:${PORTSDIR}/security/gpgme03
.else
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Define WITH_GPGME=yes to build with gpgme support."
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/env perl|${PERL} -w|" \
		${WRKSRC}/src/elmoconf.pl

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
