PORTNAME=	kineto
DISTVERSION=	g20211104
PORTREVISION=	27
CATEGORIES=	www

MAINTAINER=	corey@electrickite.org
COMMENT=	HTTP to Gemini proxy
WWW=		https://git.sr.ht/~sircmpwn/kineto/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text

SH_COMMIT=	857f8c97ebc5
# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	sircmpwn:${PORTNAME}:${SH_COMMIT}:"" \
		adnano:go-gemini:v0.1.17:vendor/git.sr.ht/~adnano/go-gemini \
		sircmpwn:getopt:23622cc906b3:vendor/git.sr.ht/~sircmpwn/getopt

WRKSRC=		${WRKDIR}/${PORTNAME}-${SH_COMMIT}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g}
MASTER_SITES+=	https://git.sr.ht/~${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project:S/-/_/g}
DISTFILES+=	${account}-${project}-${tag}_SRHT0${EXTRACT_SUFX}:${account}_${project:S/-/_/g}
.endfor

post-extract:
.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g:[5..-1]}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${MV} ${WRKDIR}/${project}-${tag} ${WRKSRC}/${subdir}
.endfor

.include <bsd.port.post.mk>
