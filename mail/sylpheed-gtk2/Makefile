# New ports collection makefile for:	sylpheed-gtk2
# Date created:                 25 September 2003
# Whom:                         Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		sylpheed-gtk2
PORTVERSION=		0.9.99.20041024
PORTREVISION=	2
CATEGORIES=		mail ipv6
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		sylpheed-${PORTVERSION:R}-gtk2-${PORTVERSION:E}

MAINTAINER=		jylefort@brutele.be
COMMENT=		The GTK+ 2.0 port of a lightweight, featureful and fast e-mail client

USE_GETTEXT=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_X_PREFIX=		yes
USE_GNOME=		gtk20
USE_LIBTOOL_VER=	15
USE_REINPLACE=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"

OPTIONS=		SSL "SSL support" off \
			GPGME "GnuPG support (using GPGME)" off \
			COMPFACE "X-Face support (using compface)" off \
			JPILOT "JPilot support" off \
			LDAP "LDAP support" off

CONFLICTS=		sylpheed-0.*

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl
.endif

.if defined(WITH_GPGME)
LIB_DEPENDS+=		gpgme03.9:${PORTSDIR}/security/gpgme03
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
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		 s|-lresolv||g; s|-lpisock\"|-liconv &|g; \
		 s|^manualdir=.*|manualdir="${DOCSDIR}/manual"|g; \
		 s|^faqdir=.*|faqdir="${DOCSDIR}/faq"|g ;\
		 s|gpgme-config|gpgme03-config|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^SUBDIRS = ac po src manual faq$$|SUBDIRS = ac po src|g' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
