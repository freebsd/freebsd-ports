# New ports collection makefile for:	elmo
# Date created:				2003-09-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	elmo
PORTVERSION=	1.2.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Receive, filter, read, compose and send mail at the text console

CONFLICTS=	elmo-devel-*

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		elmo.1 elmoconf.pl.1

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
