# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Mail-LMLM
PORTVERSION=	0.6802
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	List of Mailing Lists Manager

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::LMLM.3 Mail::LMLM::Object.3 Mail::LMLM::Render.3 \
		Mail::LMLM::Render::HTML.3 Mail::LMLM::Types::Base.3 \
		Mail::LMLM::Types::Egroups.3 Mail::LMLM::Types::Ezmlm.3 \
		Mail::LMLM::Types::GoogleGroups.3 \
		Mail::LMLM::Types::Listar.3 Mail::LMLM::Types::Listserv.3 \
		Mail::LMLM::Types::Mailman.3 Mail::LMLM::Types::Majordomo.3

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

.include <bsd.port.mk>
