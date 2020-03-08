# Created by: Frank Altpeter <frank@altpeter.de>
# $FreeBSD$

PORTNAME=	centerim
PORTVERSION=	4.22.10.11
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/mobshots/ \
		ftp://ftp.centerim.org/mobshots/
PKGNAMESUFFIX=	-devel

MAINTAINER=	frank@altpeter.de
COMMENT=	Text mode menu- and window-driven IM interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		iconv gmake ncurses perl5 pkgconfig python:2.7,run shebangfix ssl
USE_CXXSTD=	gnu++98
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl --with-openssl --without-msn --without-yahoo
CPPFLAGS+=	-I${LOCALBASE}/include
CONFLICTS=	centericq-[0-9]* centerim-[0-9]*

SHEBANG_FILES=	misc/cimformathistory misc/cimextracthistory.pl misc/CenterIMLog2HTML.py
SHEBANG_LANG=	gawk
gawk_OLD_CMD=	/bin/gawk
gawk_CMD=	/usr/bin/awk

OPTIONS_DEFINE=	NLS MULTIBYTE FRIBIDI IRC JABBER GPGME RSS LJ GG DOCS

FRIBIDI_DESC=	Fribidi Support
IRC_DESC=	IRC Protocol
GPGME_DESC=	PGP encrypted Jabber messages
RSS_DESC=	RSS Support
LJ_DESC=	LiveJournal Support
GG_DESC=	Gadu-Gadu Protocol Support

OPTIONS_DEFAULT=	MULTIBYTE FRIBIDI IRC JABBER GPGME RSS LJ GG

OPTIONS_SUB=	yes

PORTDOCS=	FAQ README

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
MULTIBYTE_CONFIGURE_ENABLE=locales-fix
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_WITH=	fribidi
IRC_CONFIGURE_ENABLE=	irc
JABBER_CONFIGURE_ENABLE=jabber
RSS_CONFIGURE_ENABLE=	rss
LJ_CONFIGURE_ENABLE=	lj
GG_LIB_DEPENDS=		libgadu.so:polish/libgadu
GG_CONFIGURE_ENABLE=	gg
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_OFF=	--with-gpgme-prefix=/nonexistent

post-patch:
	@${REINPLACE_CMD} -e 's|/var/run/screen|/tmp/screens|' \
		${WRKSRC}/src/icqconf.cc
	@${REINPLACE_CMD} -e 's|-R$$found_dir|-Wl,-rpath,$$found_dir|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
