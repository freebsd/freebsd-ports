# New ports collection makefile for:	sylpheed-gtk2
# Date created:                 25 September 2003
# Whom:                         Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		sylpheed-gtk2
PORTVERSION=		0.9.8a.20040109
CATEGORIES=		mail ipv6
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		sylpheed-${PORTVERSION:R}-gtk2-${PORTVERSION:E}

MAINTAINER=		jylefort@brutele.be
COMMENT=		The GTK+ 2.0 port of a lightweight, featureful and fast e-mail client

LIB_DEPENDS=		intl.5:${PORTSDIR}/devel/gettext \
			iconv.3:${PORTSDIR}/converters/libiconv

USE_GMAKE=		yes
USE_X_PREFIX=		yes
USE_GNOME=		gtk20
USE_OPENSSL=		yes
USE_LIBTOOL=		yes
USE_REINPLACE=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=		--enable-ssl

OPTIONS=		GPGME "GnuPG support (using GPGME)" off \
			COMPFACE "X-Face support (using compface)" off \
			JPILOT "JPilot support" off \
			LDAP "LDAP support" off

CONFLICTS=		sylpheed-0.*

.include <bsd.port.pre.mk>

.if defined(WITH_GPGME)
LIB_DEPENDS+=		gpgme.9:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--enable-gpgme
.endif

.if defined(WITH_COMPFACE)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
.else
CONFIGURE_ARGS+=	--disable-compface
.endif

.if defined(WITH_JPILOT)
LIB_DEPENDS+=		pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20-client
CONFIGURE_ARGS+=	--enable-ldap
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
