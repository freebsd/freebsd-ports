# New ports collection makefile for:	sylpheed-gtk2
# Date created:                 25 September 2003
# Whom:                         Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		sylpheed-gtk2
PORTVERSION=		0.9.5.20030906
CATEGORIES=		mail ipv6
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		sylpheed-0.9.5-gtk2-20030906

MAINTAINER=		jylefort@brutele.be
COMMENT=		The GTK+ 2.0 port of a lightweight, featureful, and fast e-mail client

USE_GMAKE=		yes
USE_X_PREFIX=		yes
USE_GNOME=		gtk20
USE_LIBTOOL=		yes
USE_REINPLACE=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=		--prefix=${PREFIX} --enable-ipv6

.include <bsd.port.pre.mk>

.if defined(WITH_GPGME)
LIB_DEPENDS+=		gpgme.9:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--enable-gpgme
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif

.if defined(WITH_COMPFACE)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--enable-compface
.else
CONFIGURE_ARGS+=	--disable-compface
.endif

.if defined(WITH_JPILOT)
LIB_DEPENDS+=		pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20-client
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

MAKEFILES=		Makefile.in		\
			ac/Makefile.in		\
			faq/Makefile.in		\
			faq/de/Makefile.in 	\
			faq/en/Makefile.in	\
			faq/es/Makefile.in	\
			faq/fr/Makefile.in	\
			faq/it/Makefile.in	\
			manual/Makefile.in	\
			manual/en/Makefile.in	\
			manual/ja/Makefile.in	\
			src/Makefile.in

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
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
