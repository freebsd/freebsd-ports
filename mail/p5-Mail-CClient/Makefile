# New ports collection makefile for:	p5-Mail-CClient
# Date created:				01 July 2000
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=		CClient
PORTVERSION=		1.8
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail/HDIAS
PKGNAMEPREFIX=		p5-
DISTNAME=		Mail-Cclient-${PORTVERSION}

MAINTAINER=		mat@FreeBSD.org
COMMENT=	Perl interface to the c-client mailbox API

LIB_DEPENDS=		c-client4.8:${PORTSDIR}/mail/cclient

PERL_CONFIGURE=		yes
CONFIGURE_ARGS=		--cclient_dir=${LOCALBASE} \
		 	--with-shared_cclient \
			--with-pam \
			--with-cclient-includes=${LOCALBASE}/include/c-client

MAN3=			Mail::Cclient.3

post-patch:
	@${PERL} -pi -e 's/-lc-client/-lc-client4/g;' \
		     -e 's/"-lc"/"-L\$$CCLIENT_DIR\/lib "/g;' \
		     -e 's/ -lpam_misc//g;' \
		 ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
