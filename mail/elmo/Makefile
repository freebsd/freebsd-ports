# Created by: trevor
# $FreeBSD$

PORTNAME=	elmo
PORTVERSION=	1.3.2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Receive, filter, read, compose, and send mail at the text console

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	elmo-devel-[0-9]*

OPTIONS_DEFINE=	GPGME NLS

GNU_CONFIGURE=	yes
USES=		iconv ncurses shebangfix perl5
USE_OPENSSL=	yes
USE_PERL5=	run
SHEBANG_FILES=	src/elmoconf.pl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GPGME_DESC=		GnuPG support using GPGME
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_ENV_OFF=ac_cv_header_gpgme_h=no
NLS_CONFIGURE_ON=	--with-libintl-prefix="${LOCALBASE}"
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/if test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
