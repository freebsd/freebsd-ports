# Created by: Sevan Janiyan <venture37@geeklan.co.uk>
# $FreeBSD$

PORTNAME=	coovachilli
PORTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ap.coova.org/chilli/ \
		http://www.geeklan.co.uk/files/ \
		http://www.venture37.com/files/
DISTNAME=	coova-chilli-${PORTVERSION}

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	An access controller for wired & wireless clients

CONFLICTS=	chillispot-[0-9]*
#if __FreeBSD__ >= 10.0
#IGNORE=	Does not work correctly, awaiting new release upstream with fixes integrated.
#endif

CONFIGURE_ARGS=-localstatedir=/var
GNU_CONFIGURE=	yes
USES=		perl5 libtool
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_RC_SUBR=	coovachilli

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_MAN} ${FILESDIR}/main.conf.sample ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_MAN} ${FILESDIR}/pf.conf.sample ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_MAN} ${FILESDIR}/ipfw-config.sample ${STAGEDIR}/${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
