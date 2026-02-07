# the example is taken from https://fresnel.readthedocs.io/en/stable/examples/00-Basic-tutorials/00-Introduction.html
# image display is altered to use PIL

## generate image

import fresnel

scene = fresnel.Scene()

geometry = fresnel.geometry.Sphere(scene, N=8, radius=1.0)

geometry.position[:] = [[1,1,1],
                        [1,1,-1],
                        [1,-1,1],
                        [1,-1,-1],
                        [-1,1,1],
                        [-1,1,-1],
                        [-1,-1,1],
                        [-1,-1,-1]]


geometry.material = fresnel.material.Material(color=fresnel.color.linear([0.25,0.5,0.9]),
                                              roughness=0.8)
scene.camera = fresnel.camera.Orthographic.fit(scene)

fresnel.preview(scene)

fresnel.preview(scene, anti_alias=False)

fresnel.pathtrace(scene)

fresnel.pathtrace(scene, light_samples=40)

out = fresnel.preview(scene)
print(out[:].shape)
print(out[:].dtype)

import PIL

image = PIL.Image.fromarray(out[:], mode='RGBA')
image.save('output.png')

image = PIL.Image.fromarray(out[:,:,0:3], mode='RGB')
image.save('output.jpeg')


## display image

from PIL import Image

im = Image.open('output.png')
im.show()

im = Image.open('output.jpeg')
im.show()
