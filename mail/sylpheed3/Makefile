# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.9.8.1
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1/a/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A lightweight, featureful, and fast GTK+ based e-mail client

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-ipv6 \
		--prefix=${PREFIX} \
		--with-libintl-prefix=${LOCALBASE} \
		--program-transform-name=''

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.if defined(WITH_PIXBUF)
USE_GNOME+=	gdkpixbuf
.else
USE_GNOME+=	imlib
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PIXBUF)
CONFIGURE_ARGS+=--disable-imlib
.else
CONFIGURE_ARGS+=--disable-gdk-pixbuf
.endif
.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.9:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif
.if defined(WITH_COMPFACE)
LIB_DEPENDS+=	compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=--enable-compface
.else
CONFIGURE_ARGS+=--disable-compface
.endif
.if defined(WITH_JPILOT)
LIB_DEPENDS+=	pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=	jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=--enable-jpilot
.else
CONFIGURE_ARGS+=--disable-jpilot
.endif
.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-ldap
.else
CONFIGURE_ARGS+=--disable-ldap
.endif
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

MAKEFILES=	Makefile.in ac/Makefile.in faq/Makefile.in faq/de/Makefile.in \
		faq/en/Makefile.in faq/es/Makefile.in faq/fr/Makefile.in \
		faq/it/Makefile.in manual/Makefile.in manual/en/Makefile.in \
		manual/ja/Makefile.in src/Makefile.in

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_PIXBUF=yes   Enable GDK Pixbuf support"
	@${ECHO} "      WITH_GPGME=yes    Enable GnuPG support using GPGME."
	@${ECHO} "      WITH_COMPFACE=yes Enable X-Face support."
	@${ECHO} "      WITH_JPILOT=yes   Enable JPilot support."
	@${ECHO} "      WITH_LDAP=yes     Enable LDAP support."
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL=yes   Disable OpenSSL support."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lresolv||g; s|-lpisock\"|-liconv &|g' ${WRKSRC}/configure

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^SUBDIRS = ac po intl src manual faq$$|SUBDIRS = ac po intl src|g' \
		${WRKSRC}/Makefile.in
.else
.for i in ${MAKEFILES}
	@${REINPLACE_CMD} -e 's|^faqdir = @faqdir@$$|faqdir = ${DOCSDIR}/faq|g; \
		s|^manualdir = @manualdir@$$|manualdir = ${DOCSDIR}/manual|g' \
		${WRKSRC}/${i}
.endfor
.endif

pre-build:
	${LN} -sf ${LIBTOOL} ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${i}.jp ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
