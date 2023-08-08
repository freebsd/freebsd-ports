PORTNAME=	dlib-models
PORTVERSION=	20210513
CATEGORIES=	misc

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Trained model files for dlib example programs
WWW=		https://github.com/davisking/dlib-models

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	davisking
GH_PROJECT=	dlib-models
GH_TAGNAME=	daf943f781

NO_BUILD=	yes
NO_ARCH=	yes

MODELS=		age-predictor/dnn_age_predictor_v1.dat \
		gender-classifier/dnn_gender_classifier_v1.dat \
		dlib_face_recognition_resnet_model_v1.dat \
		mmod_dog_hipsterizer.dat \
		mmod_front_and_rear_end_vehicle_detector.dat \
		mmod_human_face_detector.dat \
		mmod_rear_end_vehicle_detector.dat \
		resnet34_1000_imagenet_classifier.dnn \
		resnet50_1000_imagenet_classifier.dnn \
		shape_predictor_5_face_landmarks.dat \
		shape_predictor_68_face_landmarks.dat \
		shape_predictor_68_face_landmarks_GTX.dat

.for f in ${MODELS}
PLIST_FILES+=	${DATADIR}/${f}
.endfor

pre-install:
.for f in ${MODELS}
	${BZIP2_CMD} -d ${WRKSRC}/${f}.bz2
	${RM} ${f}.bz2
.endfor

do-install:
	cd ${WRKSRC}/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${FIND} ${STAGEDIR}${DATADIR} -name '*.cpp' -delete
	${RM} ${STAGEDIR}${DATADIR}/LICENSE
	${RM} ${STAGEDIR}${DATADIR}/README.md

.include <bsd.port.mk>
