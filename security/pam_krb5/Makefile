# Ports collection Makefile for:	pam_krb5
# Date created:				11/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pam_krb5
PORTVERSION=		1.3.r7
CATEGORIES=		security
MASTER_SITE_SOURCEFORGE+=	http://unc.dl.sourceforge.net/%SUBDIR%/ \
			http://umn.dl.sourceforge.net/%SUBDIR%/ \
			http://twtelecom.dl.sourceforge.net/%SUBDIR%/ \
			http://aleron.dl.sourceforge.net/%SUBDIR%/ \
			http://easynews.dl.sourceforge.net/%SUBDIR%/ \
			http://switch.dl.sourceforge.net/%SUBDIR%/ \
			http://cesnet.dl.sourceforge.net/%SUBDIR%/ \
			http://flow.dl.sourceforge.net/%SUBDIR%/ \
			http://keihanna.dl.sourceforge.net/%SUBDIR%/ \
			http://heanet.dl.sourceforge.net/%SUBDIR%/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.komquats.com/distfiles/
MASTER_SITE_SUBDIR=	sourceforge/${PORTNAME:S/_/-/}
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=	A Pluggable Authentication Module for Kerberos 5

MAN8=			pam_krb5.8

USE_SIZE=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.if defined(PACKAGE_BUILDING)
KRB5_IMPL=		mit
.endif

.if defined(KRB5_IMPL) && ${KRB5_IMPL} == heimdal
LIB_DEPENDS=		krb5.18:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.endif
.elif defined(KRB5_IMPL) && ${KRB5_IMPL} == mit
LIB_DEPENDS=		krb5.3:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.endif
.else
BROKEN=			You must define KRB5_IMPL to be \"mit\" or \"heimdal\"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=			FreeBSD 5.x already ships with its own version of pam_krb5
.endif
MANDIR=			${MANPREFIX}/man
PREFIX=			${DESTDIR}/usr
MANPREFIX=		${DESTDIR}/usr/share
MANDIR=			${PREFIX}/share/man
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ENV=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"	\
			--with-pamdir="${PREFIX}/lib"	\
			--with-man-sect=8		\
			--mandir=${MANDIR}		\
			--without-krbafs

post-install:
	cd ${WRKSRC} && ${GMAKE} install-man

.include <bsd.port.post.mk>
