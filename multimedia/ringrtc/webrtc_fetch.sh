#!/bin/sh

WEBRTC_REV=4896c

base_url="https://chromium.googlesource.com/chromium/src/base.git/+archive/"
boringssl_url="https://boringssl.googlesource.com/boringssl.git/+archive/"
build_url="https://chromium.googlesource.com/chromium/src/build.git/+archive/"
buildtools_url="https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/"
catapult_url="https://chromium.googlesource.com/catapult.git/+archive/"
icu_url="https://chromium.googlesource.com/chromium/deps/icu.git/+archive/"
libjpeg_turbo_url="https://chromium.googlesource.com/chromium/deps/libjpeg_turbo.git/+archive/"
libsrtp_url="https://chromium.googlesource.com/chromium/deps/libsrtp.git/+archive/"
libvpx_url="https://chromium.googlesource.com/webm/libvpx.git/+archive/"
libyuv_url="https://chromium.googlesource.com/libyuv/libyuv.git/+archive/"
nasm_url="https://chromium.googlesource.com/chromium/deps/nasm.git/+archive/"
testing_url="https://chromium.googlesource.com/chromium/src/testing.git/+archive/"
third_party_url="https://chromium.googlesource.com/chromium/src/third_party.git/+archive/"

fetch -q -o /tmp/DEPS https://raw.githubusercontent.com/signalapp/webrtc/${WEBRTC_REV}/DEPS

base_hash=$(grep 'base@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BASE_REV=\t${base_hash}\n"

boringssl_hash=$(grep 'boringssl.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BORINGSSL_REV=\t${boringssl_hash}\n"

build_hash=$(grep 'build@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILD_REV=\t${build_hash}\n"

buildtools_hash=$(grep 'buildtools@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILDTOOLS_REV=\t${buildtools_hash}\n"

catapult_hash=$(grep 'catapult.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "CATAPULT_REV=\t${catapult_hash}\n"

icu_hash=$(grep 'icu.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "ICU_REV=\t${icu_hash}\n"

libjpeg_turbo_hash=$(grep 'libjpeg_turbo.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBJPEG_TURBO_REV=\t${libjpeg_turbo_hash}\n"

libsrtp_hash=$(grep 'libsrtp.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBSRTP_REV=\t${libsrtp_hash}\n"

libvpx_hash=$(grep 'libvpx.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBVPX_REV=\t${libvpx_hash}\n"

libyuv_hash=$(grep 'libyuv.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBYUV_REV=\t${libyuv_hash}\n"

nasm_hash=$(grep 'nasm.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "NASM_REV=\t${nasm_hash}\n"

testing_hash=$(grep 'testing@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "TESTING_REV=\t${testing_hash}\n"

third_party_hash=$(grep 'third_party@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "THIRD_PARTY_REV=\t${third_party_hash}\n"

echo "fetch -o base-${base_hash}.tar.gz ${base_url}${base_hash}.tar.gz"
echo "fetch -o boringssl-${boringssl_hash}.tar.gz ${boringssl_url}${boringssl_hash}.tar.gz"
echo "fetch -o build-${build_hash}.tar.gz ${build_url}${build_hash}.tar.gz"
echo "fetch -o buildtools-${buildtools_hash}.tar.gz ${buildtools_url}${buildtools_hash}.tar.gz"
echo "fetch -o catapult-${catapult_hash}.tar.gz ${catapult_url}${catapult_hash}.tar.gz"
echo "fetch -o icu-${icu_hash}.tar.gz ${icu_url}${icu_hash}.tar.gz"
echo "fetch -o libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz ${libjpeg_turbo_url}${libjpeg_turbo_hash}.tar.gz"
echo "fetch -o libsrtp-${libsrtp_hash}.tar.gz ${libsrtp_url}${libsrtp_hash}.tar.gz"
echo "fetch -o libvpx-${libvpx_hash}.tar.gz ${libvpx_url}${libvpx_hash}.tar.gz"
echo "fetch -o libyuv-${libyuv_hash}.tar.gz ${libyuv_url}${libyuv_hash}.tar.gz"
echo "fetch -o nasm-${nasm_hash}.tar.gz ${nasm_url}${nasm_hash}.tar.gz"
echo "fetch -o testing-${testing_hash}.tar.gz ${testing_url}${testing_hash}.tar.gz"
echo "fetch -o third_party-${third_party_hash}.tar.gz ${third_party_url}${third_party_hash}.tar.gz"

exit

mkdir -p base boringssl build buildtools catapult icu libjpeg_turbo libsrtp libvpx libyuv nasm testing third_party
tar xf base-${base_hash}.tar.gz -C base
tar xf boringssl-${boringssl_hash}.tar.gz -C boringssl
tar xf build-${build_hash}.tar.gz -C build
tar xf buildtools-${buildtools_hash}.tar.gz -C buildtools
tar xf catapult-${catapult_hash}.tar.gz -C catapult
tar xf icu-${icu_hash}.tar.gz -C icu
tar xf libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz -C libjpeg_turbo
tar xf libsrtp-${libsrtp_hash}.tar.gz -C libsrtp
tar xf libvpx-${libvpx_hash}.tar.gz -C libvpx
tar xf libyuv-${libyuv_hash}.tar.gz -C libyuv
tar xf nasm-${nasm_hash}.tar.gz -C nasm
tar xf testing-${testing_hash}.tar.gz -C testing
tar xf third_party-${third_party_hash}.tar.gz -C third_party

tar czf /tmp/base-${base_hash}.tar.gz base
tar czf /tmp/boringssl-${boringssl_hash}.tar.gz boringssl
tar czf /tmp/build-${build_hash}.tar.gz build
tar czf /tmp/buildtools-${buildtools_hash}.tar.gz buildtools
tar czf /tmp/catapult-${catapult_hash}.tar.gz catapult
tar czf /tmp/icu-${icu_hash}.tar.gz icu
tar czf /tmp/libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz libjpeg_turbo
tar czf /tmp/libsrtp-${libsrtp_hash}.tar.gz libsrtp
tar czf /tmp/libvpx-${libvpx_hash}.tar.gz libvpx
tar czf /tmp/libyuv-${libyuv_hash}.tar.gz libyuv
tar czf /tmp/nasm-${nasm_hash}.tar.gz nasm
tar czf /tmp/testing-${testing_hash}.tar.gz testing
tar czf /tmp/third_party-${third_party_hash}.tar.gz third_party

rm -rf base boringssl build buildtools catapult icu libjpeg_turbo libsrtp libvpx libyuv nasm testing third_party

exit 
