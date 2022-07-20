PORTNAME=	coovachilli
PORTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ap.coova.org/chilli/ \
		http://www.geeklan.co.uk/files/ \
		http://www.venture37.com/files/
DISTNAME=	coova-chilli-${PORTVERSION}

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	Access controller for wired & wireless clients

CONFLICTS=	chillispot
#if __FreeBSD__ >= 10.0
#IGNORE=	Does not work correctly, awaiting new release upstream with fixes integrated.
#endif

CONFIGURE_ARGS=-localstatedir=/var
GNU_CONFIGURE=	yes
USES=		cpe perl5 libtool
CPE_VENDOR=	${PORTNAME}_project
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_RC_SUBR=	coovachilli

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/main.conf.sample ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/pf.conf.sample ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/ipfw-config.sample ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
