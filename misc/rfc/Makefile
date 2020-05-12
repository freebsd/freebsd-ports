# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	rfc
PORTVERSION=	3.2.3
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	https://BSDforge.com/projects/source/misc/rfc/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Perl script to search for RFC's

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	w3m:www/w3m

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	${PORTNAME}-${PORTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/rfc man/man1/rfc.1.gz

do-configure:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/rfc|${PREFIX}/etc/rfc| ; \
		s|/usr/local/etc/nmap|${PREFIX}/share/misc/nmap| ; \
		s|400k|1024k| ; \
		s|http://ftp.isi.edu/in-notes|http://www.ietf.org/rfc| ; \
		s|http://www.iana|ftp://ftp.iana|' \
		${WRKSRC}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
